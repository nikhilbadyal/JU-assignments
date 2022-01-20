package assignmentwo.wrapperclass07;

import assignmentwo.library03.booklist.Book;

/**
 * @author Nikhil
 * @date 07 Feb2020
 */

interface WrapperInterface {
    // Basic to Object
    Integer int2Int(int i );
    Float float2Float(float f );
    Long long2Long(long l);
    Boolean bool2Bool(boolean b);
    Character char2Char(char c);

    // Object to basic
    int Int2int(Integer i);
    long Long2long(Long l);
    float Float2float(Float f);
    char Char2char(Character c);
    boolean Bool2bool(Boolean b);

    // Basic type to string
    String int2String(int i);
    String long2String(long l);
    String float2String(float f);
    String char2String(char c);
    String bool2String(boolean b);


    //String holding numeric data



    //Object to string
    int String2int(String i);
    long String2long(String l);
    float String2float(String f);
    char String2char(String  c);
    boolean String2bool(String b);

}
   
