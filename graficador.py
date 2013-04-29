import pylab
import numpy


time_interval = 3.0/10.0
n_points = 1000;
	
for i in range(20):

	if(i < 11):
		data = numpy.loadtxt(open(str(i)+'.dat', 'r'))
		u = data[:, 0]
		x = linspace(0.0, 1.0, n_points)
		
		pylab.plot(x, u)
		pylab.xlabel('x')
		pylab.ylabel('u(x)')
		pylab.title('x-u_1')
		pylab.savefig('x-u_1.png')
	
	else:
		data = numpy.loadtxt(open(str(i)+'.dat', 'r'))
		u = data[:, 0]
		x = linspace(-5.0, 5.0, n_points)
		
		pylab.plot(x, u)
		pylab.xlabel('x')
		pylab.ylabel('u(x)')
		pylab.title('x-u_2')
		pylab.savefig('x-u_2.png')

