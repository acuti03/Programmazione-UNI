package esercitazione_2;

import java.io.*;
import java.net.*;

public class Client {
  public static void main(String[] args) {

    if(args.length != 2) {
      System.err.println("Usage: java QuoteClient hostname porta");
      System.exit(1);
    }

    try {
      DatagramSocket ds = new DatagramSocket();
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));


      byte[] reqBuf = new String(in.readLine()).getBytes("UTF-8");
      DatagramPacket dp = new DatagramPacket(reqBuf, reqBuf.length, InetAddress.getByName(args[0]), Integer.parseInt(args[1]));

      ds.send(dp);

      byte[] respBuf = new byte[2048];
      DatagramPacket respPacket = new DatagramPacket(respBuf, respBuf.length);

      ds.receive(respPacket);
      
      String quote = new String(respPacket.getData(), 0, respPacket.getLength(), "UTF-8");
      System.out.println(quote);

      ds.close();

    } catch (IOException e) {
      System.err.println(e.getMessage());
      e.printStackTrace();
      System.exit(1);
    }
  }
}
