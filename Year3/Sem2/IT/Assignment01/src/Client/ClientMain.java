package Client;

public class ClientMain {
    public static void main(String[] args){
        int defaultPort = 0;
        if (args.length != 1) {
            System.out.println("Usage <portNumber>");
            System.exit(1);
        }
        try {
            defaultPort = Integer.parseInt(args[0]);
        }catch (Exception e) {
            System.out.println("Wrong input format. Using default settings.");
        }
            Client client = new Client("localhost", defaultPort);
            client.connect();
    }
}

