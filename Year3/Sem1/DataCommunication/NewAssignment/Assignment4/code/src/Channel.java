import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.SocketTimeoutException;

public class Channel {

    public static void send(String Frame, ObjectOutputStream objectOutputStream)   {


        try{
            System.out.println("Sending frame from channel");
            objectOutputStream.writeObject((String)Frame);
          //  System.out.println(Frame);

        }catch(IOException e){
            System.out.println("IOException " + e);
        }
    }

    public static void sendAck(String ack, ObjectOutputStream objectOutputStream){
        try {
            objectOutputStream.writeObject(ack);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static boolean getAck(ObjectInputStream objectInputStream, Socket s) throws IOException, ClassNotFoundException {
        s.setSoTimeout(1000);

        try{
          //  System.out.println("Waiting for acknowledgement");
            String ack = (String)objectInputStream.readObject();
            return ack.equals("resend");
        }catch(SocketTimeoutException socketTimeoutException){
            System.out.println("SomeThing bad happened, data lost (no ack, Timeout)\n\n\n");
            return true;
        }
    }

}
