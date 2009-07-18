#! /usr/bin/env python
import libgexf
from libgexf import *
input_file = "../../../../t/attributes.gexf"
output_file = "../../../../t/writer_test.gexf"
reader = FileReader()
reader.init(input_file)
reader.slurp()
gexf = reader.getGEXFCopy()
gexf.checkIntegrity()
writer = FileWriter()
writer.init(output_file,gexf)
writer.write()

