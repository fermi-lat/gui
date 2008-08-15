# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/gui/guiLib.py,v 1.1 2008/07/09 21:13:47 glastrm Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['gui'])
	env.Tool('addLibrary', library = ['guisystem'])

def exists(env):
    return 1;
