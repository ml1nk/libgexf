import java.util.Set;


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
        org.gephi.libgexf.GEXF gexf = new org.gephi.libgexf.GEXF();
        System.out.println( "    Created gexf " + gexf );
        org.gephi.libgexf.DirectedGraph graph = gexf.getDirectedGraph();
        
        // ----- Generate data -----
        graph.writeLock();
        for (int i=0; i<100; i++) {
            graph.addNode(i);
        }
        for (int i=0; i<99; i++) {
            graph.addEdge(i, i, i+1); // chain
        }
        try {
            graph.readLock();
        } catch (Exception e) {
            System.err.println("Assert readLock exception:\n" + e);
        }
        graph.writeUnlock();
        
        
        // ----- Member data access -----
        System.out.println("node count: " + graph.getNodeCount());
        System.out.println("edge count: " + graph.getEdgeCount());
        
        Set neighbors = graph.getNeighbors(3);
        
        // ----- Call some methods -----
        
        // ----- Delete everything -----
    
        // Note: this invokes the virtual destructor
        // You could leave this to the garbage collector
        gexf.delete();
        
        System.out.println( "Goodbye" );
  }
}

