# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/gui/SConscript,v 1.16 2013/02/20 20:16:08 jrb Exp $
# Authors: T.Burnett <tburnett@u.washington.edu>
# Version: gui-03-09-00
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package = 'gui', toBuild='static')
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
objList = []
if baseEnv['PLATFORM'] == 'win32':
    guiSystem = libEnv.StaticLibrary('guisystem',
                                     ['src/WinGUI.cxx', 'src/WinGUIostream.cxx',
                                      'src/WinScene.cxx',
                                      'src/WinDraw.cxx'])
    WinMainObj = libEnv.Object('src/WinMain.cxx')
    winguiRES  = libEnv.RES('src/wingui.rc')
    guiForMain = libEnv.StaticLibrary('guiForMain', [WinMainObj, winguiRES])
    ##objList += [[WinMainObj, libEnv], [winguiRES, libEnv]]

else:
    guiSystem = libEnv.StaticLibrary('guisystem',
                                     ['src/MotifGUI.cxx', 'src/XScene.cxx',
                                      'src/Xdraw.cxx', 'src/Xostream.cxx'])

progEnv.Tool('guiLib')
testsrcs = listFiles(['src/test/*.cxx'])
if baseEnv['PLATFORM'] == 'win32':
    testsrcs += [WinMainObj, winguiRES]
testGui = progEnv.Program('testGui', testsrcs)

if baseEnv['PLATFORM'] == 'win32':
    progEnv.Tool('registerTargets', package = 'gui',
                 staticLibraryCxts = [[gui, libEnv], [guiSystem, libEnv],
                                      [guiForMain, libEnv]],
             testAppCxts = [[testGui, progEnv]], 
             includes = listFiles(['gui/*.h']) )
else:
    progEnv.Tool('registerTargets', package = 'gui',
                 staticLibraryCxts = [[gui, libEnv], [guiSystem, libEnv]],
                 testAppCxts = [[testGui, progEnv]], 
                 includes = listFiles(['gui/*.h']))






