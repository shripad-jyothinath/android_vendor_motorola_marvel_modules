// Ghidra headless script: decompile every function to <out>/<program>.c
// and write a function/call table to <out>/<program>.functions.tsv.
// Usage: -postScript ExportDecomp.java <outDir>

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Program;
import ghidra.program.model.address.Address;
import java.io.File;
import java.io.PrintWriter;

public class ExportDecomp extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("ExportDecomp: missing output directory");
            return;
        }
        File outDir = new File(args[0]);
        if (!outDir.exists() && !outDir.mkdirs()) {
            println("ExportDecomp: cannot create " + outDir);
            return;
        }

        Program program = currentProgram;
        String name = program.getName();
        DecompInterface decomp = new DecompInterface();
        decomp.toggleCCode(true);
        decomp.toggleSyntaxTree(true);
        decomp.setSimplificationStyle("decompile");
        if (!decomp.openProgram(program)) {
            println("ExportDecomp: cannot open program for decompilation");
            return;
        }

        FunctionManager fm = program.getFunctionManager();
        File cFile = new File(outDir, name + ".c");
        File tsvFile = new File(outDir, name + ".functions.tsv");

        int ok = 0, failed = 0;
        try (PrintWriter cw = new PrintWriter(cFile);
             PrintWriter tw = new PrintWriter(tsvFile)) {
            cw.println("// Decompiled by Ghidra " + getGhidraVersion());
            cw.println("// Program: " + name);
            cw.println("// Image base: " + program.getImageBase());
            cw.println();
            tw.println("name\tentry\tsize\tcallers\tcallees");

            for (Function f : fm.getFunctions(true)) {
                Address ep = f.getEntryPoint();
                String callers = "";
                String callees = "";
                try {
                    callers = f.getCallingFunctions(monitor).toString();
                    callees = f.getCalledFunctions(monitor).toString();
                } catch (Exception ignored) {
                }
                tw.println(f.getName() + "\t" + ep + "\t" + f.getBody().getNumAddresses()
                        + "\t" + callers.replace('\t', ' ') + "\t" + callees.replace('\t', ' '));

                DecompileResults res = decomp.decompileFunction(f, 60, monitor);
                if (res != null && res.decompileCompleted() && res.getDecompiledFunction() != null) {
                    cw.println("//------------------------------------------------------------");
                    cw.println("// " + f.getName() + " @ " + ep + " size=" + f.getBody().getNumAddresses());
                    if (f.getSignature() != null) {
                        cw.println("// signature: " + f.getSignature());
                    }
                    if (callers.length() > 0) {
                        cw.println("// callers: " + callers);
                    }
                    cw.println("//------------------------------------------------------------");
                    cw.println(res.getDecompiledFunction().getC());
                    cw.println();
                    ok++;
                } else {
                    cw.println("// FAILED TO DECOMPILE: " + f.getName() + " @ " + ep);
                    cw.println();
                    failed++;
                }
            }
        }
        decomp.dispose();
        println("ExportDecomp: " + name + " functions_ok=" + ok + " failed=" + failed);
    }
}
