package es2;

import java.io.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class Sorter implements Runnable{
    
    private ThreadLoad threadLoad;
    private PipedOutputStream pos;
    private AtomicBoolean running;

    public Sorter(ThreadLoad threadLoad, PipedOutputStream pos){
        this.threadLoad = threadLoad;
        this.pos = pos;
        running = new AtomicBoolean(false);
    }

    @Override
    public void run(){

        running.set(true);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));

        while (running.get()) {
            try {
                Integer ti = threadLoad.getMaxThreadId();

                if(ti == null) continue;

                Double cpuLoad = threadLoad.getCpuLoad(ti);

                if(cpuLoad == null) continue;

                String result = "Thread " + ti + " con cpuLoad " + cpuLoad;
                bw.write(result);
                bw.newLine();
                bw.flush();
                Thread.sleep(150);
            }
            catch (InterruptedException | IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void stop(){

        if(running.get()){
            running.set(false);
        }
    }
}
