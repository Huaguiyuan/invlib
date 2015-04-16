import sys
import os
from pylab import *
import matplotlib.gridspec as gridspec
from mpl_toolkits.axes_grid1 import make_axes_locatable
import numpy as np
import matplotlib.pyplot as plt
import scipy.interpolate
import math
from matplotlib import ticker
import matplotlib.patheffects as PathEffects
from matplotlib import rc

rc('text', usetex=True)
matplotlib.rcParams.update({'font.size': 38})

inputfile = 'OUTPUT.dat'
outputfile = 'out.pdf'

fig = figure(num=None, figsize=(8,7),dpi=80)
gs = gridspec.GridSpec(1,1)
ax1 = plt.subplot(gs[0])

def main():
	data = np.genfromtxt(inputfile,skip_header=1)
	x = data[:,0]
	y = data[:,1]
	z = data[:,2]
	xi, yi = np.linspace(x.min(), x.max(), 300), np.linspace(y.min(), y.max(), 300)
	xi, yi = np.meshgrid(xi, yi)
	zi = scipy.interpolate.griddata((x, y), z, (xi, yi), method='linear')
	im1 = ax1.imshow(zi, vmin=z.min(), vmax=z.max(), origin='lower', aspect='equal', extent=[x.min(), x.max(), y.min(), y.max()])	
	divider1 = make_axes_locatable(ax1)	
	cax1 = divider1.append_axes('right', size='5%', pad=0.15)
	cbar = plt.colorbar(im1, cax=cax1,ticks=[0,1,2])
	tick_locator = ticker.MaxNLocator(nbins=5)
	cbar.locator = tick_locator
	cbar.update_ticks()
	cbar.set_ticks([0,1,2])
	cbar.set_ticklabels([r'$0$',r'$1$',r'$2$'])		
	ax1.locator_params(axis='x',nbins=4)
	ax1.locator_params(axis='y',nbins=4)
	ax1.set_aspect('auto')
	ax1.set_xlabel(r"$\Delta$")
	ax1.set_ylabel(r"$\mu$",rotation='horizontal')
	ax1.yaxis.set_label_coords(-0.07, 0.7)

main()
fig.tight_layout()
plt.savefig('plot.pdf', bbox_inches='tight')



