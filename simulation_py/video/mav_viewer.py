"""
mavsim_python: mav viewer (for chapter 2)
    - Beard & McLain, PUP, 2012
    - Update history:
        2/24/2020 - RWB
"""
import sys
sys.path.append("..")
import numpy as np
import pyqtgraph as pg
from PyQt5 import QtWidgets  
import pyqtgraph.opengl as gl
import pyqtgraph.Vector as Vector
from tools.drawing import drawMav


class mavViewer():
    def __init__(self):
        # initialize Qt gui application and window
        self.app = QtWidgets.QApplication([])  # initialize QT
        self.window = gl.GLViewWidget()  # initialize the view object
        self.window.setWindowTitle('MAV Viewer')
        self.window.setGeometry(0, 0, 1000, 1000)  # args: upper_left_x, upper_right_y, width, height
        grid = gl.GLGridItem()  # make a grid to represent the ground
        grid.setSize(500,500,500) # set the span of the grid 
        grid.scale(20, 20, 20)  # set the size of the grid (distance between each line)
        self.window.addItem(grid)  # add grid to viewer
        self.window.setCameraPosition(distance=150) # distance from center of plot to camera
        self.window.setBackgroundColor('k')  # set background color to black
        self.window.show()  # display configured window
        self.window.raise_()  # bring window to the front
        self.plot_initialized = False  # has the mav been plotted yet?
        self.mav_plot = []

    def update(self, state):
        # initialize the drawing the first time update() is called
        if not self.plot_initialized:
            self.mav_plot = drawMav(state, self.window)
            self.plot_initialized = True
        # else update drawing on all other calls to update()
        else:
            self.mav_plot.update(state)
        # update the center of the camera view to the mav location
        view_location = Vector(state.pe, state.pn, state.h)  # defined in ENU coordinates
        self.window.opts['center'] = view_location
        self.window.setCameraPosition(azimuth=-np.degrees(state.psi+state.beta)-90,elevation=-np.degrees(state.theta)+10)
        # redraw
        self.app.processEvents()
