package com.nikhil;


/**
 * @author Nikhil
 * @date 22 Feb2020
 */

public class ReaderWriterDemo {
    public static void main(String[] args) {
        Data data = new Data();
        Reader reader = new Reader(data);
        Writer writer = new Writer(data);

        reader.startThread();
        writer.startThread();

    }
}
   
