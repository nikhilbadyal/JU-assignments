package util;
import java.io.Serializable;

public class AckPackage implements  Serializable {
    String status ;
    String crc ;
    private static final long serialVersionUID = 2L;
    private int frameNo;

    public AckPackage(String status, int frameNo) {
        this.status = status;
        this.frameNo = frameNo;
    }
    public AckPackage(String status) {
        this.status = status;
    }

    public void setCrc(String crc) {
        this.crc = crc;
    }

    public String getStatus() {
        return  status;
    }
}
