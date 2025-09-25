cat $1 | grep -i nicolas | grep -i bomber | sed -n 'p;n' | cut -f 3 
