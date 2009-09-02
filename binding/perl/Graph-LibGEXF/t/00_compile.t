# see http://perldoc.perl.org/Test/More.html
#     http://search.cpan.org/~adie/Test-Exception-0.27/lib/Test/Exception.pm

use strict;
use Error qw(:try);
use Test::More tests => 6;
use Test::Exception;


BEGIN { use_ok 'Graph::LibGEXF' }
#require_ok( 'Graph::LibGEXF' );


my $gexf = Graph::LibGEXF::GEXF->new();

my $graph = $gexf->getDirectedGraph();

# create 100 nodes
for(0..99) {
    $graph->addNode("$_");
}

# create 99 edges
for(0..98) {
    my $t = $_+1;
    $graph->addEdge("$_","$_","$t");
}



is($graph->getNodeCount(), 100, "Node count");
is($graph->getEdgeCount(), 99, "Edge count");

is($graph->getInDegree("1"), 1, "InDegree");
is($graph->getOutDegree("1"), 1, "OutDegree");



# TODO mapping sets
my $neighbors = $graph->getNeighbors("1");
#is($neighbors[0], 2, "Neighbors");



#test exceptions
try {
    $graph->addEdge("999999","999999","1000000");
} catch Error with {
    my $ex = shift;
    print "Error: Caught Exception occurred\n";
    is($ex, "RuntimeError Invalid source node 999999 for the edge 999999\n", "invalid_argument caught as expected");
}
# non-obvious problem for testing...
#throws_ok( sub { $graph->addEdge(999999,999999,1000000) }, '/RuntimeError/', 'invalid_argument caught okay');



# test import file
#my $reader = Graph::LibGEXF::FileReader->new("../../../t/attributes.gexf");
#$reader->slurp();
#my $gexf_import = $reader->getGEXFCopy();
#my $valid = $gexf_import->checkIntegrity();
#is($valid, 1, "Integrity");



#if( $valid ) {
    # test export file
#    my $writer = Graph::LibGEXF::FileWriter->new();
#    writer->init("../../../t/writer_test.gexf", $gexf);
#    writer->write();
#}



# test XSD validation
#my $isValid = Graph::LibGEXF::SchemaValidator::run("../../../t/attributes.gexf", "../../../resources/xsd/1.1draft.xsd");




