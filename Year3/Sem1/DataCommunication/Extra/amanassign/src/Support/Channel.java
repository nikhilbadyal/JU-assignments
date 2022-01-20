package Support;

import java.util.Random;

public class Channel {
    Random random;
    public Channel(){
        random = new Random();
    }
    public String addSingleBitError(String s){
        String frame= s;
        int length = frame.length();
        char errorChar = (char) (random.nextInt(93)+'!');
        int posForError = random.nextInt(length);
        frame = frame.substring(0,posForError)+errorChar+frame.substring(posForError+1);
        return frame;
    }

    public String addBurstError(String s){
        String frame= s;
        int length = frame.length();
        int noOfErrors = random.nextInt(length);
        for(int i =0 ; i < noOfErrors ; ++i){
            char errorChar = (char) (random.nextInt(93)+'!');
            int posForError = random.nextInt(length);
            frame = frame.substring(0,posForError)+errorChar+frame.substring(posForError+1);
        }

        return frame;
    }

    public void addDelay() {
        Random RANDOM = new Random();
        try {
            boolean shouldInject = RANDOM.nextBoolean();
            if(shouldInject){
                int switchCase = RANDOM.nextInt(2);
                switch (switchCase){
                    case 0:
                        Thread.sleep(1000);
                        break;
                    case 1:
                        //Do nothing.
                        break;
                    default:
                        //do nothing
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
            Thread.currentThread().interrupt();
        }

    }
}
