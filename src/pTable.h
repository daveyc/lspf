/*
  Copyright (c) 2015 Daniel John Erdos

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

class Table
{
	public:
		Table()
		{
			CRP           = 0     ;
			maxURID       = 0     ;
			firstMult     = true  ;
			changed       = false ;
			tab_cmds      = false ;
			tab_ipath     = ""    ;
			tab_opath     = ""    ;
			sa_namelst    = ""    ;
			sa_cond_pairs = ""    ;
			sa_dir        = "NEXT";
			sort_ir       = ""    ;
		}
		~Table() ;
	private:
		bool    tab_cmds      ;
		string  tab_name      ;
		string  tab_keys      ;
		string  tab_flds      ;
		string  tab_all       ;
		string  tab_ipath     ;
		string  tab_opath     ;
		bool    firstMult     ;
		bool    changed       ;
		uint    maxURID       ;
		uint    num_keys      ;
		uint    num_flds      ;
		uint    num_all       ;
		uint    CRP           ;
		uint    CRPX          ;
		string  sort_ir       ;
		string  sa_namelst    ;
		string  sa_cond_pairs ;
		string  sa_dir        ;
		tbDISP  tab_DISP      ;
		tbWRITE tab_WRITE     ;

		vector<vector<string>*> table ;
		vector<tbsearch> sarg    ;
		vector<string> tab_vkeys ;
		vector<string> tab_vall  ;

		map<uint,uint>openTasks ;

		bool   tableClosedforTask( errblock& err ) ;

		bool   tableOpenedforTask( errblock& err ) ;

		void   addTasktoTable( errblock& err ) ;

		void   removeTaskUsefromTable( errblock& err ) ;

		void   removeTaskfromTable( errblock& err ) ;

		bool   notInUse() ;

		string listTasks() ;

		void   saveTable( errblock& err,
				  const string& m_name,
				  const string& m_path ) ;

		void   loadRow( errblock& err,
				vector<string>* m_flds ) ;

		void   reserveSpace( int tot_rows ) ;

		void   resetChanged() { changed = false ; }

		void   storeIntValue( errblock& err,
				      fPOOL& funcPOOL,
				      const string&,
				      int,
				      int =8 ) ;

		void   fillfVARs( errblock& err,
				  fPOOL& funcPOOL,
				  const set<string>& tb_fields,
				  const set<string>& tb_clear,
				  bool scan,
				  uint depth,
				  int  posn,
				  uint csrrow,
				  int& idx ) ;

		void   cmdsearch( errblock& err,
				  fPOOL& funcPOOL,
				  const string& cmd ) ;


		vector<vector<string>*>::iterator getKeyItr( errblock& err,
							     fPOOL& funcPOOL ) ;

		void   loadfuncPOOL( errblock& err,
				     fPOOL& funcPOOL,
				     const string& savename ) ;

		void   saveExtensionVarNames( errblock& err,
					      fPOOL& funcPOOL,
					      const string& savename ) ;

		void   loadFields( errblock& err,
				   fPOOL& funcPOOL,
				   const string& tb_namelst,
				   vector<string>* flds ) ;

		void   loadFields_save( errblock& err,
					fPOOL& funcPOOL,
					const string& tb_savenm,
					const string& tb_rowid_vn,
					const string& tb_noread,
					const string& tb_crp_name ) ;

		void   tbadd( errblock& err,
			      fPOOL& funcPOOL,
			      string tb_namelst,
			      string tb_order,
			      int tb_num_of_rows )  ;

		void   tbbottom( errblock& err,
				 fPOOL& funcPOOL,
				 string tb_savenm,
				 string tb_rowid_vn,
				 string tb_noread,
				 string tb_crp_name ) ;

		void   tbdelete( errblock& err,
				 fPOOL& funcPOOL ) ;

		void   tbexist( errblock& err,
				fPOOL& funcPOOL ) ;

		void   tbget( errblock& err,
			      fPOOL& funcPOOL,
			      string tb_savenm,
			      string tb_rowid_vn,
			      string tb_noread,
			      string tb_crp_name ) ;

		void   tbmod( errblock& err,
			      fPOOL& funcPOOL,
			      string tb_namelst,
			      string tb_order ) ;

		void   tbput( errblock& err,
			      fPOOL& funcPOOL,
			      string tb_namelst,
			      string tb_order ) ;

		void   tbquery( errblock& err,
				fPOOL& funcPOOL,
				string tb_keyn,
				string tb_varn,
				string tb_rownn,
				string tb_keynn,
				string tb_namenn,
				string tb_crpn,
				string tb_sirn,
				string tb_lstn,
				string tb_condn,
				string tb_dirn ) ;

		void   tbsarg( errblock& err,
			       fPOOL& funcPOOL,
			       string tb_namelst,
			       string tb_next_prev,
			       string tb_cond_pairs ) ;

		void   setscan( errblock& err,
				fPOOL& funcPOOL,
				vector<tbsearch>& scan,
				set<string>& names,
				string& tb_namelst,
				string& tb_cond_pairs ) ;

		void   tbscan( errblock& err,
			       fPOOL& funcPOOL,
			       string tb_namelst,
			       string tb_varname,
			       string tb_rowid_vn,
			       string tb_next_prev,
			       string tb_read,
			       string tb_crp_name,
			       string tb_condlst ) ;

		void   tbskip( errblock& err,
			       fPOOL& funcPOOL,
			       int num,
			       string tb_savenm,
			       string tb_rowid_vn,
			       const string& tb_rowid,
			       string tb_noread,
			       string tb_crp_name ) ;

		void   tbsort( errblock& err,
			       string tb_fields ) ;

		void   tbtop( errblock& err ) ;

		void   tbvclear( errblock& err,
				 fPOOL& funcPOOL ) ;

		friend class tableMGR ;
} ;


class tableMGR
{
	public:
		tableMGR() {} ;
		~tableMGR() ;

		static logger* lg ;

		multimap<string, Table*>::iterator loadTable( errblock& err,
							      const string& tb_name,
							      tbWRITE=WRITE,
							      const string& src="",
							      tbDISP=NON_SHARE ) ;

		void   saveTable( errblock& err,
				  const string& tb_func,
				  const string& tb_name,
				  const string& m_newname,
				  const string& m_path ) ;

		void   tbadd( errblock& err,
			      fPOOL& funcPOOL,
			      const string& tb_name,
			      const string& tb_namelst,
			      const string& tb_order,
			      int tb_num_of_rows ) ;

		void tbcreate( errblock& err,
			       const string& tb_name,
			       string keys,
			       string flds,
			       tbREP m_REP,
			       tbWRITE m_WRITE,
			       const string& m_path,
			       tbDISP m_DISP ) ;

		void   tbsort( errblock& err,
			       const string& tb_name,
			       const string& tb_fields ) ;

		void   statistics() ;

		void   cmdsearch( errblock& err,
				  fPOOL& funcPOOL,
				  string tb_name,
				  const string& cmd,
				  const string& paths,
				  bool  try_load ) ;

	private:
		multimap<string, Table*> tables ;

		map<Table*, string> table_enqs ;

		boost::recursive_mutex mtx ;

		multimap<string, Table*>::iterator getTableIterator1( errblock& err,
								      const string& tb_name ) ;

		multimap<string, Table*>::iterator getTableIterator2( errblock& err,
								      const string& tb_name ) ;

		multimap<string, Table*>::iterator createTable( errblock& err,
								const string& tb_name,
								string keys,
								string flds,
								tbWRITE m_WRITE,
								tbDISP m_DISP ) ;

		int    enq( Table* tab,
			    const string& tb_name ) ;

		int    deq( Table* tab ) ;

		Table* qscan( const string& filename ) ;

		void   fillfVARs( errblock& err,
				  fPOOL& funcPOOL,
				  const string& tb_name,
				  const set<string>& tb_fields,
				  const set<string>& tb_clear,
				  bool scan,
				  int  depth,
				  int  posn,
				  int  csrrow,
				  int& idx ) ;

		void   destroyTable( errblock& err,
				     const string& tb_name,
				     const string& tb_func = "" ) ;

		void   closeTablesforTask( errblock& err ) ;

		void   qtabopen( errblock& err,
				 fPOOL& funcPOOL,
				 const string& tb_list ) ;

		void   tbbottom( errblock& err,
				 fPOOL& funcPOOL,
				 const string& tb_name,
				 const string& tb_savenm,
				 const string& tb_rowid_vn,
				 const string& tb_noread,
				 const string& tb_crp_name ) ;

		void   tbdelete( errblock& err,
				 fPOOL& funcPOOL,
				 const string& tb_name ) ;

		void   tberase( errblock& err,
				const string& tb_name,
				const string& tb_path ) ;

		void   tbexist( errblock& err,
				fPOOL& funcPOOL,
				const string& tb_name ) ;

		void   tbget( errblock& err,
			      fPOOL& funcPOOL,
			      const string& tb_name,
			      const string& tb_savenm,
			      const string& tb_rowid_vn,
			      const string& tb_noread,
			      const string& tb_crp_name  ) ;

		void   tbmod( errblock& err,
			      fPOOL& funcPOOL,
			      const string& tb_name,
			      const string& tb_namelst,
			      const string& tb_order ) ;

		void   tbput( errblock& err,
			      fPOOL& funcPOOL,
			      const string& tb_name,
			      const string& tb_namelst,
			      const string& tb_order ) ;

		void   tbquery( errblock& err,
				fPOOL& funcPOOL,
				const string& tb_name,
				const string& tb_keyn,
				const string& tb_varn,
				const string& tb_rownn,
				const string& tb_keynn,
				const string& tb_namenn,
				const string& tb_crpn,
				const string& tb_sirn,
				const string& tb_lstn,
				const string& tb_condn,
				const string& tb_dirn ) ;

		void   tbsarg( errblock& err,
			       fPOOL& funcPOOL,
			       const string& tb_name,
			       const string& tb_namelst,
			       const string& tb_next_prev,
			       const string& tb_cond_pairs ) ;

		void   tbskip( errblock& err,
			       fPOOL& funcPOOL,
			       const string& tb_name,
			       int num,
			       const string& tb_varname,
			       const string& tb_rowid_vn,
			       const string& tb_rowid,
			       const string& tb_noread,
			       const string& tb_crp_name ) ;

		void   tbscan( errblock& err,
			       fPOOL& funcPOOL,
			       const string& tb_name,
			       const string& tb_namelst,
			       const string& tb_savenm,
			       const string& tb_rowid_vn,
			       const string& tb_next_prev,
			       const string& tb_read,
			       const string& tb_crp_name,
			       const string& tb_condlst ) ;

		void   tbtop( errblock& err,
			      const string& tb_name ) ;

		void   tbvclear( errblock& err,
				 fPOOL& funcPOOL,
				 const string& tb_name ) ;

		bool   writeableTable( errblock& err,
				       const string& tb_name,
				       const string& tb_func ) ;

		string locate( errblock& err,
			       const string& tb_name,
			       const string& tb_path ) ;

		friend class pApplication ;
} ;

#undef llog
#undef debug1
#undef debug2


#define llog(t, s) \
{ \
lg->lock() ; \
(*lg) << microsec_clock::local_time() << \
" TABLE     " << \
" " << d2ds( err.taskid, 5 ) << " " << t << " " << s ; \
lg->unlock() ; \
}

#ifdef DEBUG1
#define debug1( s ) \
{ \
lg->lock() ; \
(*lg) << microsec_clock::local_time() << \
" TABLE     " << \
" " << d2ds( err.taskid, 5 ) <<  \
" D line: "  << __LINE__  << \
" >>L1 Function: " << __FUNCTION__ << \
" -  " << s ; \
lg->unlock() ; \
}
#else
#define debug1( s )
#endif


#ifdef DEBUG2
#define debug2( s ) \
{ \
lg->lock() ; \
(*lg) << microsec_clock::local_time() << \
" TABLE     " << \
" " << d2ds( err.taskid, 5 ) <<  \
" D line: "  << __LINE__  << \
" >>L2 Function: " << __FUNCTION__ << \
" -  " << s ; \
lg->unlock() ; \
}
#else
#define debug2( s )
#endif
