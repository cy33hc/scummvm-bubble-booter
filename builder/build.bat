@set /p title="Insert bubble name: "
@set /p path="Insert game fullpath: "
@set /p game_id="Insert game id: "
@set /p id="Insert bubble title ID (9 characters [NOTE: Only UPPERCASE letters or numbers]) Example SCMVM0001: "
@echo|set /p="%path%"> "contents/path.txt"
@echo|set /p="%game_id%"> "contents/game_id.txt"
vita-mksfoex -s TITLE_ID=%id% "%title%" param.sfo
vita-pack-vpk -s param.sfo -b eboot.bin "%title%.vpk" -a contents/icon0.png=sce_sys/icon0.png -a contents/bg.png=sce_sys/livearea/contents/bg.png -a contents/startup.png=sce_sys/livearea/contents/startup.png -a contents/template.xml=sce_sys/livearea/contents/template.xml -a contents/path.txt=path.txt -a contents/game_id.txt=game_id.txt