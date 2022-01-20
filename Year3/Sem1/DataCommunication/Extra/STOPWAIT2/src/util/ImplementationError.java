package util;

public class ImplementationError extends Exception {
  //  public ImplementationError() { throw  new UnsupportedOperationException("Please provide Explanation of Error.");}
    public ImplementationError(String s) { super(s); }
}
