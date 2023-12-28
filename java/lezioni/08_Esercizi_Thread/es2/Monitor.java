package es2;

import java.util.concurrent.atomic.AtomicBoolean;
import java.util.*;

public class Monitor implements Runnable{

    private ThreadLoad threadLoad;
    private final AtomicBoolean running;
    
    public Monitor(ThreadLoad threadLoad){
        this.threadLoad = threadLoad;
        running = new AtomicBoolean(false);
    }

    @Override
    public void run(){
        
        running.set(true);
        final Random random = new Random();

        while (running.get()) {
            try {
                final int threadId = random.nextInt(9) + 1;
                final double cpuLoad = random.nextDouble() * 100;
                threadLoad.setThreadLoad(threadId, cpuLoad);
                Thread.sleep(200);
            }
            catch (InterruptedException e) {
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
