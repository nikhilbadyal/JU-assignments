package sender;
import Util.Channel;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.util.Random;

public class PhysicalLayer {
    private PhysicalLayer() {
        throw new UnsupportedOperationException("Utility Class.");
    }
    static Channel channel = new Channel();


    public static String sendFrame(String frame, int portNumber,int frameNo){
        String host = "localhost";
        String status ;
        /*Random random = new Random();
        boolean shouldInject = random.nextBoolean();
        if(shouldInject){
            System.out.println("Frame before error injection "+frame);
            frame = channel.InjectBrustError(frame,24);
            System.out.println("Frame after error injection "+frame);
        }*/
        try(Socket s= new Socket(host,portNumber)) {
            System.out.println("Client Started at port Number "+portNumber);
            DataOutputStream dataOutputStream = new DataOutputStream(s.getOutputStream());
            System.out.println("Sending frame "+frame+" at port "+portNumber);
            dataOutputStream.writeUTF(frame);
            DataInputStream dataInputStream = new DataInputStream(s.getInputStream());
            System.out.println("Waiting for acknowledgment for frame "+(frameNo));
            status = dataInputStream.readUTF();
            System.out.println("Acknowledgement received with status "+status);
        } catch (Exception e) {
            status =  "Receiver not responding.";
        }
        return  status;
    }
}
