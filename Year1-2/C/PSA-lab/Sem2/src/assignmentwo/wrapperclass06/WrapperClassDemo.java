package assignmentwo.wrapperclass07;

/**
 * @author Nikhil
 * @date 02 Feb2020
 */

public class WrapperClassDemo implements  WrapperInterface {
    @Override
    public Integer int2Int(int i) {
        return 4 ; // new Integer(i);
    }

    @Override
    public Float float2Float(float f) {
        return null;
    }

    @Override
    public Long long2Long(long l) {
        return null;
    }

    @Override
    public Boolean bool2Bool(boolean b) {
        return null;
    }

    @Override
    public Character char2Char(char c) {
        return null;
    }

    @Override
    public int Int2int(Integer i) {
        return 0;
    }

    @Override
    public long Long2long(Long l) {
        return 0;
    }

    @Override
    public float Float2float(Float f) {
        return 0;
    }

    @Override
    public char Char2char(Character c) {
        return 0;
    }

    @Override
    public boolean Bool2bool(Boolean b) {
        return false;
    }

    @Override
    public String int2String(int i) {
        return null;
    }

    @Override
    public String long2String(long l) {
        return null;
    }

    @Override
    public String float2String(float f) {
        return null;
    }

    @Override
    public String char2String(char c) {
        return null;
    }

    @Override
    public String bool2String(boolean b) {
        return null;
    }

    @Override
    public int String2int(String i) {
        return 0;
    }

    @Override
    public long String2long(String l) {
        return 0;
    }

    @Override
    public float String2float(String f) {
        return 0;
    }

    @Override
    public char String2char(String c) {
        return 0;
    }

    @Override
    public boolean String2bool(String b) {
        return false;
    }
}
   
