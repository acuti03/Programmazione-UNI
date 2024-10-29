package esercitazione_2;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class Server {
  public static void main(String[] args) {

    if (args.length != 1) {
      System.err.println("Usage: java QuoteServer porta");
      System.exit(1);
    }

    try {
      DatagramSocket ds = new DatagramSocket(Integer.parseInt(args[0]));

      while (true) {
        byte[] buf = new byte[2048];
        DatagramPacket dp = new DatagramPacket(buf, buf.length);
        ds.receive(dp);

        String quote = new String(dp.getData(), 0, dp.getLength(), "UTF-8");
        System.out.println(quote);

        dp.setLength(buf.length);
        ds.send(dp);
      }
    } catch (IOException e) {
      System.err.println(e.getMessage());
      e.printStackTrace();
      System.exit(1);
    }

  }
}
