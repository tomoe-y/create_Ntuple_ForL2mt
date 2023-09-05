import os

user    = 'user.toyamash' # 'group.det-muon'
athena  = '22.0.107'
version = 'Run3-' + athena + '-00-01'
#version = 'MC'
retry   = '7'

listfile = open('RUN3_l2mt_0821.list')
#listfile = open('MC_0904.list')
AODs = listfile.readlines() 
listfile.close()

for AOD in AODs:
    AOD = AOD.rstrip()
    command =  'pathena MyAnalysis/ATestRun_jobOptions.py'
    #command += ' %IN %OUT.root"'
    #command += ' --athenaTag=%s' % athena
    #command += ' --nGBPerJob=MAX'
    #command += ' --nFilesPerJob=1'
    command += ' --useNewCode'
    command += ' --maxCpuCount 86400'
    command += ' --nEventsPerJob 100000'
    command += ' --mergeOutput'
    command += ' --forceStaged'
    command += ' --memory 2048'
    command += ' --nCore 8'
    command += ' --inDS=%s' % AOD
    
    #output = ESD.replace('DESDM_MCP', 'NTUP_MCP.' + retry)
    #output = output.replace('DESDM_ZMUMU', 'NTUP_ZMUMU.' + retry)
    #output = output.replace('DESDM_TILEMU', 'NTUP_TILEMU.' + retry)
    #output = output.replace('ESD', 'NTUP.' + retry)
    output = AOD.replace('recon.AOD', 'MC')
    
    command += ' --outDS=%s.%s.%s.%s_NTUP' % (user, output, version, retry)

    print(command)
    os.system(command)
