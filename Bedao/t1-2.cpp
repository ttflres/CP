for(int i=1;i<=n;i++) vec[a[i].x].pb(a[i].y); memset(tr,0,sizeof tr);  
	for(int i=1;i<=n;i++){ 
		for(int j=0;j<vec[i].size();j++){ 
			int to=vec[i][j]; 
			ans-=query(to+1),add(to); 
		} for(int j=0;j<vec[i].size();j++) clear(vec[i][j]); 
	} printf("%lld\n",ans); 
