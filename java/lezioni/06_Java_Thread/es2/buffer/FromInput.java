package es2.buffer;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PipedOutputStream;

public class FromInput extends Thread {

    private PipedOutputStream pos;

	public FromInput(PipedOutputStream pos){
		this.pos = pos;
	}

    public void run(){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = null;
        
        try {
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));
            System.out.println("FromInput - inserire uno o piu messaggi: ");

            while ((line = br.readLine()) != null) {
                bw.write(line);
                bw.newLine();
                bw.flush();
            }
        }
        catch (IOException e) {
            System.out.println(e);
        }
    }


}
