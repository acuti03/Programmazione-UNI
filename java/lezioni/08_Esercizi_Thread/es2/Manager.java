package es2;

import java.io.*;

public class Manager extends Thread{
    
    private Monitor monitor;
    private Sorter sorter;
    private PipedInputStream pis;


    public Manager(Monitor monitor, Sorter sorter, PipedInputStream pis){
        this.monitor = monitor;
        this.sorter = sorter;
        this.pis = pis;
    }

    @Override
    public void run(){

        BufferedReader br = new BufferedReader(new InputStreamReader(pis));

        for(int i = 0; i < 10; i++){
            try {
                String line = br.readLine();
                System.out.println(line);
            }
            catch (IOException e) {
                e.printStackTrace();
            }
        }
        monitor.stop();
        sorter.stop();
    }
}
