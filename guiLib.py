# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/gui/guiLib.py,v 1.2 2008/08/15 21:42:39 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['gui'])
    env.Tool('addLibrary', library = ['guisystem'])
    env.Tool('addLibrary', library = env['x11Libs'])
    env.Tool('addLibrary', library = env['clhepLibs'])
def exists(env):
    return 1;
