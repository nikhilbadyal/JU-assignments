package util;
import java.io.Serializable;

public class Frame implements  Serializable {
    String mainFrame ;
    int frameNo ;
    private static final String DESTINATION_MAC = "80-91-33-93-B7-7F"; //17
    private static final String FIELD_DIVIDER = "-";
    private static final String NORMAL_FRAME_TYPE = "N";
    private static final long serialVersionUID = 1L;

    public Frame(String frame, int frameNo) {
        this.mainFrame = frame;
        this.frameNo = frameNo;
    }

    public String getFrame() {
        return mainFrame;
    }

    public void setFrame(String frame) {
        this.mainFrame = frame;
    }

    public int getFrameNo() {
        return frameNo;
    }

    public void setFrameNo(int frameNo) {
        this.frameNo = frameNo;
    }

    public boolean isLast() {
        String str = mainFrame.substring(2 * (DESTINATION_MAC.length() + FIELD_DIVIDER.length()) ,2 * (DESTINATION_MAC.length() + FIELD_DIVIDER.length() )+ NORMAL_FRAME_TYPE.length());
        return  str.equals("E");
    }
}

