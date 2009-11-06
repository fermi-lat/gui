# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/gui/SConscript,v 1.5 2009/08/07 00:49:22 jrb Exp $
# Authors: T.Burnett <tburnett@u.washington.edu>
# Version: gui-03-07-03
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('guiLib', depsOnly = 1)
gui = libEnv.StaticLibrary('gui',
                           listFiles(['src/LoopCommand.cxx','src/SceneControl.cxx',
                                      'src/Menu.cxx', 'src/SubMenu.cxx',
                                      'src/CompoundCommand.cxx','src/ViewPort.cxx',
                                      'src/DisplayControl.cxx', 'src/Vrml.cxx',
                                      'src/DisplayList.cxx', 'src/PSdraw.cxx',
                                      'src/DisplayRep.cxx','src/GraphicsVector.cxx',
                                      'src/PrintControl.cxx', 'src/GuiMgr.cxx',
                                      'src/Projector.cxx', 'src/Scene.cxx',
                                      'src/GUI.cxx']))
if baseEnv['PLATFORM'] == 'win32':
    guiSystem = libEnv.StaticLibrary('guisystem',
                                     ['src/WinGUI.cxx', 'src/WinGUIostream.cxx',
                                      'src/WinMain.cxx', 'src/WinScene.cxx',
                                      'src/WinDraw.cxx'])
else:
    guiSystem = libEnv.StaticLibrary('guisystem',
                                     ['src/MotifGUI.cxx', 'src/XScene.cxx',
                                      'src/Xdraw.cxx', 'src/Xostream.cxx'])

progEnv.Tool('guiLib')
testGui = progEnv.Program('testGui', listFiles(['src/test/*.cxx']))

progEnv.Tool('registerTargets', package = 'gui',
             staticLibraryCxts = [[gui, libEnv], [guiSystem, libEnv]],
             testAppCxts = [[testGui, progEnv]], includes = listFiles(['gui/*.h']))




