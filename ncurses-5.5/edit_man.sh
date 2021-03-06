#! /bin/sh
# this script is generated by the configure-script CF_MAN_PAGES macro.
prefix="/usr"
datadir="${prefix}/share"
NCURSES_OSPEED="short"
TERMINFO="/usr/share/terminfo"
MKDIRS="sh /home/vaibhav/Downloads/ncurses-5.5/mkinstalldirs"
INSTALL="/usr/bin/install -c"
INSTALL_DATA="${INSTALL} -m 644"
transform="s,x,x,"

TMP=${TMPDIR-/tmp}/man$$
trap "rm -f $TMP" 0 1 2 5 15

form=$1
shift || exit 1

verb=$1
shift || exit 1

mandir=$1
shift || exit 1

srcdir=$1
top_srcdir=$srcdir/..
shift || exit 1

if test "$form" = normal ; then
	if test "no" = yes ; then
	if test "no" = no ; then
		sh $0 format $verb $mandir $srcdir $*
		exit 0
	fi
	fi
	cf_subdir=$mandir/man
	cf_tables=no
else
	cf_subdir=$mandir/cat
	cf_tables=yes
fi

# process the list of source-files
for i in $* ; do
case $i in #(vi
*.orig|*.rej) ;; #(vi
*.[0-9]*)
	section=`expr "$i" : '.*\.\([0-9]\)[xm]*'`;
	if test $verb = installing ; then
	if test ! -d $cf_subdir${section} ; then
		$MKDIRS $cf_subdir$section
	fi
	fi
	aliases=
	source=`basename $i`
	inalias=$source
	test ! -f $inalias && inalias="$srcdir/$inalias"
	if test ! -f $inalias ; then
		echo .. skipped $source
		continue
	fi
	aliases=`sed -f $top_srcdir/man/manlinks.sed $inalias | sort -u`
	target=`grep "^$source" /home/vaibhav/Downloads/ncurses-5.5/man/man_db.renames | mawk '{print $2}'`
	if test -z "$target" ; then
		echo '? missing rename for '$source
		target="$source"
	fi
	target="$cf_subdir${section}/${target}"
	prog_captoinfo=`echo captoinfo|sed "${transform}"`
	prog_clear=`echo clear|sed "${transform}"`
	prog_infocmp=`echo infocmp|sed "${transform}"`
	prog_infotocap=`echo infotocap|sed "${transform}"`
	prog_tic=`echo tic|sed "${transform}"`
	prog_toe=`echo toe|sed "${transform}"`
	prog_tput=`echo tput|sed "${transform}"`
	sed	-e "s,@DATADIR@,$datadir," \
		-e "s,@TERMINFO@,$TERMINFO," \
		-e "s,@NCURSES_OSPEED@,$NCURSES_OSPEED," \
		-e "s,@CAPTOINFO@,$prog_captoinfo," \
		-e "s,@CLEAR@,$prog_clear," \
		-e "s,@INFOCMP@,$prog_infocmp," \
		-e "s,@INFOTOCAP@,$prog_infotocap," \
		-e "s,@TIC@,$prog_tic," \
		-e "s,@TOE@,$prog_toe," \
		-e "s,@TPUT@,$prog_tput," \
		< $i | sed -f /home/vaibhav/Downloads/ncurses-5.5/edit_man.sed >$TMP
if test $cf_tables = yes ; then
	tbl $TMP >$TMP.out
	mv $TMP.out $TMP
fi
	if test $form = format ; then
		nroff -man $TMP >$TMP.out
		mv $TMP.out $TMP
	fi
	if test $verb = installing ; then
	if ( gzip -f $TMP )
	then
		mv $TMP.gz $TMP
	fi
	fi
	target="$target.gz"
	suffix=`basename $target | sed -e 's%^[^.]*%%'`
	if test $verb = installing ; then
		echo $verb $target
		$INSTALL_DATA $TMP $target
		test -n "$aliases" && (
			cd $cf_subdir${section} && (
				source=`echo $target |sed -e 's%^.*/\([^/][^/]*/[^/][^/]*$\)%\1%'`
				test -n "gz" && source=`echo $source |sed -e 's%\.gz$%%'`
				target=`basename $target`
				for cf_alias in $aliases
				do
					if test $section = 1 ; then
						cf_alias=`echo $cf_alias|sed "${transform}"`
					fi

					if test "yes" = yes ; then
						if test -f $cf_alias${suffix} ; then
							if ( cmp -s $target $cf_alias${suffix} )
							then
								continue
							fi
						fi
						echo .. $verb alias $cf_alias${suffix}
						rm -f $cf_alias${suffix}
						ln -s $target $cf_alias${suffix}
					elif test "$target" != "$cf_alias${suffix}" ; then
						echo ".so $source" >$TMP
						if test -n "gz" ; then
							gzip -f $TMP
							mv $TMP.gz $TMP
						fi
						echo .. $verb alias $cf_alias${suffix}
						rm -f $cf_alias${suffix}
						$INSTALL_DATA $TMP $cf_alias${suffix}
					fi
				done
			)
		)
	elif test $verb = removing ; then
		echo $verb $target
		rm -f $target
		test -n "$aliases" && (
			cd $cf_subdir${section} && (
				for cf_alias in $aliases
				do
					if test $section = 1 ; then
						cf_alias=`echo $cf_alias|sed "${transform}"`
					fi

					echo .. $verb alias $cf_alias${suffix}
					rm -f $cf_alias${suffix}
				done
			)
		)
	else
#		echo ".hy 0"
		cat $TMP
	fi
	;;
esac
done

if test no = yes ; then
if test $form != format ; then
	sh $0 format $verb $mandir $srcdir $*
fi
fi

exit 0
