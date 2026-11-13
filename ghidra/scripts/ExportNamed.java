// Ghidra headless script: promote local ELF symbols to functions, then
// decompile functions whose name matches a regex.
// Usage: -postScript ExportNamed.java <outDir> <regex>

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Program;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SymbolType;
import ghidra.program.model.mem.MemoryBlock;
import java.io.File;
import java.io.PrintWriter;
import java.util.regex.Pattern;

public class ExportNamed extends GhidraScript {
    private boolean executable(Program p, Address a) {
        MemoryBlock b = p.getMemory().getBlock(a);
        return b != null && b.isExecute();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("ExportNamed: need <outDir> <regex>");
            return;
        }
        File outDir = new File(args[0]);
        if (!outDir.exists() && !outDir.mkdirs()) return;
        Pattern pat = Pattern.compile(args[1]);

        Program program = currentProgram;
        SymbolTable st = program.getSymbolTable();
        FunctionManager fm = program.getFunctionManager();

        int created = 0;
        SymbolIterator it = st.getAllSymbols(true);
        while (it.hasNext()) {
            Symbol s = it.next();
            String name = s.getName();
            if (name == null || name.isEmpty() || !pat.matcher(name).find()) continue;
            Address a = s.getAddress();
            if (a == null || !executable(program, a)) continue;
            if (fm.getFunctionAt(a) != null) continue;
            SymbolType t = s.getSymbolType();
            if (t != SymbolType.LABEL && t != SymbolType.FUNCTION) continue;
            try {
                createFunction(a, name);
                created++;
            } catch (Exception ignored) {
            }
        }

        DecompInterface decomp = new DecompInterface();
        decomp.toggleCCode(true);
        decomp.toggleSyntaxTree(true);
        decomp.setSimplificationStyle("decompile");
        if (!decomp.openProgram(program)) return;

        String tag = program.getName() + ".selected";
        File cFile = new File(outDir, tag + ".c");
        File tsvFile = new File(outDir, tag + ".functions.tsv");
        int ok = 0, failed = 0, n = 0;
        try (PrintWriter cw = new PrintWriter(cFile);
             PrintWriter tw = new PrintWriter(tsvFile)) {
            cw.println("// Ghidra " + getGhidraVersion() + " symbol-driven decompilation");
            cw.println("// Program: " + program.getName() + " regex=" + args[1]);
            tw.println("name\tentry\tsize");
            for (Function f : fm.getFunctions(true)) {
                String name = f.getName();
                if (!pat.matcher(name).find()) continue;
                n++;
                tw.println(name + "\t" + f.getEntryPoint() + "\t" + f.getBody().getNumAddresses());
                DecompileResults res = decomp.decompileFunction(f, 120, monitor);
                if (res != null && res.decompileCompleted() && res.getDecompiledFunction() != null) {
                    cw.println("//------------------------------------------------------------");
                    cw.println("// " + name + " @ " + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses());
                    cw.println("// signature: " + f.getSignature());
                    cw.println("//------------------------------------------------------------");
                    cw.println(res.getDecompiledFunction().getC());
                    cw.println();
                    ok++;
                } else {
                    cw.println("// FAILED: " + name + " @ " + f.getEntryPoint());
                    failed++;
                }
            }
        }
        decomp.dispose();
        println("ExportNamed: promoted=" + created + " matched=" + n + " ok=" + ok + " failed=" + failed);
    }
}
