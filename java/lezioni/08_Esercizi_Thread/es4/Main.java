package es2;

import java.io.*;

import es2.stream.MacchinaA;
import es2.stream.MacchinaB;

public class Main {
    public static void main(String[] args) {
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        MacchinaA mA = new MacchinaA(pos);
        Thread tmA = new Thread(mA);
        tmA.start();

        MacchinaB mb = new MacchinaB(pis);
        Thread tmB = new Thread(mb);
        tmB.start();

        try {
            Thread.sleep(10000);
            mA.stop();
            mb.stop();
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }

        try{
            tmA.join();
            tmB.join();
        }
        catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}
