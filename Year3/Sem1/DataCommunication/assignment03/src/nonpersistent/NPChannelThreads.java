package nonpersistent;

/*Class to check which station's frame the current transmission is colliding with.

 */
public class NPChannelThreads {
    private NPChannelThreads(){throw new UnsupportedOperationException("Util Class.");}

    public static int checking(String name) {
        int stat = -1 ;
        try{
            stat = Integer.parseInt(name.substring(8));
        }catch (NumberFormatException e ){
            //Some Error.
            System.out.println("NPChannel name I got is "+name);
        }
        return  stat;
    }

}