nbvar = 5000
varname = 'a'
with open('perf5000_decl_aff_wri.lt','w') as f:
	f.write('var ')
	for i in range(nbvar):
		if(i == nbvar-1):
			f.write(varname+str(i)+';\n')
		else:
			f.write(varname+str(i)+', ')
	for i in range(nbvar):
		f.write(varname+str(i)+ ':='+str(i)+';\n')
	for i in range(nbvar):
		f.write('ecrire '+varname+str(i)+';\n')

