
public class runme {
  static {
    try {
//        System.loadLibrary("libgexf");

        // Linux hack, if you can't get your library
        // path set in your environment
        System.load("/home/sebastien/NetBeansProjects/libgexf/binding/java/libgexf.so");
    } catch (UnsatisfiedLinkError e) {
        System.err.println("Native code library failed to load. See the chapter on Dynamic Linking Problems in the SWIG Java documentation for help.\n" + e);
        System.exit(1);
    }
  }

  public static void main(String argv[]) {
        // ----- Object creation -----
        System.out.println( "Creating some objects:" );
        GEXF g = new GEXF();
        System.out.println( "    Created gexf " + g );
        
        // ----- Member data access -----
        
        // ----- Call some methods -----
        
        // ----- Delete everything -----
    
        // Note: this invokes the virtual destructor
        // You could leave this to the garbage collector
        g.delete();
        
        System.out.println( "Goodbye" );
  }
}

