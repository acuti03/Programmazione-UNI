package esercitazione_1;

import java.io.*;
import java.net.*;

class Client {
  public static void main(String[] args) throws IOException {
    String N = null;
    final int PORT = 9090;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    Socket socket = new Socket("127.0.0.1", PORT);

    while (true) {
      System.out.println("Enter the number: ");
      N = br.readLine();

      if(N.equals("fine")) {
        socket.close();
        System.exit(0);
      }

  
      PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
      output.println(N);
  
      BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
      String message = input.readLine();
      System.out.println(message); 
    }
  }
}