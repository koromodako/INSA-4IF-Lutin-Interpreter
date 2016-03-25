nbvar = 3
varname = 'a'
constname = 'c'
with open('perf3_o','w') as f:
	f.write('var ')
	for i in range(nbvar):
		if(i == nbvar-1):
			f.write(varname+str(i)+';\n')
		else:
			f.write(varname+str(i)+', ')

	f.write('const ')
	for i in range(nbvar):
		if(i == nbvar -1):
			f.write(constname+str(i)+'='+str(i)+';\n')
		else:
			f.write(constname+str(i)+'='+str(i)+', ')

	for i in range(nbvar):
		f.write(varname+str(i)+ ':='+str(i)+'+'+constname+str(i)+';\n')
	for i in range(nbvar):
		f.write('ecrire '+varname+str(i)+';\n')

