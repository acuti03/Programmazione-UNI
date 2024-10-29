package esercitazione_1;

import java.io.*;
import java.net.*;

public class Server {
 public static void main(String[] args) throws IOException {
  final int PORT = 9090;
  ServerSocket listener = new ServerSocket(PORT);

  try {
    System.out.println("Server Running ...");

    while (true) {
      Socket socket = listener.accept();

      BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
      int N = Integer.parseInt(input.readLine());
      N *= N;
  
      PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
      out.println(N); 
    }

  } finally {
    listener.close();
    System.exit(-1);
  }
 }  
}
