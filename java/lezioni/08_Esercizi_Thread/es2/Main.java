package es2;

import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String[] args) {
        ThreadLoad threadLoad = new ThreadLoad();
        Monitor monitor = new Monitor(threadLoad);
        Thread tmonitor = new Thread(monitor);
        PipedInputStream pis = new PipedInputStream();

        try {
            PipedOutputStream pos = new PipedOutputStream(pis);
            Sorter sorter = new Sorter(threadLoad, pos);
            Thread tsorter = new Thread(sorter);
            Manager manager = new Manager(monitor, sorter, pis);

            tmonitor.start();
            tsorter.start();
            manager.start();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}
