package Server;

public class ServerMain {
    public static void main(String[] args) {
        int defaultPort = 5555;
        int maxClients = 5;
        if (args.length > 2) {
            System.out.println("Usage <portNumber> <noOfClients>");
            System.exit(1);
        }
        try {
            defaultPort = Integer.parseInt(args[0]);
        } catch (Exception e) {
            System.out.println("Wrong input format. Using default settings.");
        }
        try {
            maxClients = Integer.parseInt(args[1]);
        } catch (Exception e) {
            System.out.println("Wrong input format. Using default settings.");
        }
        Server server = new Server(defaultPort, maxClients);
        server.startServing();
    }
}
