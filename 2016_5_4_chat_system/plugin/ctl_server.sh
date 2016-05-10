#!bin/bash
proc_name=$(basename $0)
function usage()
{
	printf "%s\n" "$proc_name [(start/-s)|(stop/-t)|(restart/-rs)|(status/-a)]"
}
if [ $# -ne 1 ];then
	usage;
	exit 1
fi

case $1 in
	'start'|'-s' )
	echo "AAA"
	;;
	'stop'|'-t' )
	echo "BBB"
	;;
	* )
	usage
	exit 1
	;;
esac
