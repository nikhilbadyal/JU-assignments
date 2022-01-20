package onepersistent;

/*Class to check which station's frame the current transmission is colliding with.

 */
public class OneChannelThreads {
    private OneChannelThreads(){throw new UnsupportedOperationException("Util Class.");}

    public static int checking(String name) {
        int stat = -1 ;
        try{
            stat = Integer.parseInt(name.substring(8));
        }catch (NumberFormatException e ){
            //Some Error.
            System.out.println("Channel name I got is "+name);
        }
        return  stat;
    }
    /*public static int checking(String stationName)
    {   int stat;
        switch (stationName)
        {
            case("Station 1") : stat = 1;
                                break;
            case ("Station 2") : stat = 2;
                                break;
            case("Station 3") : stat = 3;
                                break;
            case ("Station 4") : stat = 4;
                                break;
            default : stat = 0;

        }
        return(stat);
    }*/

}