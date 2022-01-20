package ppersistent;

import utilclasses.ChannelConstants;

/*Class to check which station's frame the current transmission is colliding with.

 */
public class PChannelThreads implements ChannelConstants {
    public static int checking(String StationName)
    {   int stat;
        char c = StationName.charAt(8);
        stat = Integer.parseInt(c+"");
        return(stat);
    }
}