import pylab
import numpy


time_interval = 3.0/10.0
	
for i in range(2):

	data = numpy.loadtxt(open(str(i)+'.dat', 'r'))
	t = data[:,0]
	u = data[:,1]
	
	for j in range(10):
	
		
		pylab.plot(x, y, 'k')
		pylab.xlabel('x')
		pylab.ylabel('y')
		pylab.title(str(i)+' x-y')
		pylab.savefig(str(i)+'_x-y.png')
		pylab.close()
