#!/bin/bash

RESET=$(printf '\033[0m')

# 🎨 Couleurs ANSI simple
WHITE=$(printf '\033[0;37m')
CYAN=$(printf '\033[0;36m')
MAGENTA=$(printf '\033[0;35m')
BLUE=$(printf '\033[0;34m')
YELLOW=$(printf '\033[0;33m')
GREEN=$(printf '\033[0;32m')
RED=$(printf '\033[0;31m')
GREY=$(printf '\033[0;30m')
RESET=$(printf '\033[0m')

# 🎨 Couleurs ANSI gras
GRAS=$(printf '\033[1m')
SOULIGNE=$(printf '\033[4m')
INVERSE=$(printf '\033[7m')
MASQUE=$(printf '\033[8m')

# Others
FILLIT="0"
REPLACE="0"
# 🧭 Sauvegarde du dossier courant
INITIAL_DIR=$(pwd)

# 🔍 Recherche du projet (via Url)
URL=$2

# 🔍 Recherche du dossier 42_Paris (vrai repo Git racine)
case "$URL" in
  git@github.com:*/?*|git@github.com:*/?*.git)
	REPO_NAME=$(basename "${URL%.git}")
    ;;
  *)
    ;;
esac

# 🔍 Recherche du dossier 42_Paris (vrai repo Git racine)
CURRENT_DIR="$INITIAL_DIR"
CURRENT_DIR_NAME=""

if [ -d "$CURRENT_DIR/.git" ] || [ -f "$CURRENT_DIR/.git" ]; then
    CURRENT_DIR_NAME=$(echo "$CURRENT_DIR" | rev | cut -d'/' -f1 | rev)
else
	while [ "$CURRENT_DIR" != "/" ] && [ "$CURRENT_DIR" != "." ]; do
        CURRENT_DIR=$(dirname "$CURRENT_DIR")
        if [ -d "$CURRENT_DIR/.git" ] || [ -f "$CURRENT_DIR/.git" ]; then
            CURRENT_DIR_NAME=$(echo "$CURRENT_DIR" | rev | cut -d'/' -f1 | rev)
            break
        fi
    done
fi

LOG="log_42git.log"

############## AFFICHAGE ##############
# Fonction récupération de la taille de la ligne
get_visible_length() {
    local input="$1"
    local stripped length=0 char w i
    local esc_cleaned

    # Supprime les séquences ANSI
    esc_cleaned=$(echo "$input" | sed -E 's/\x1B\[[0-9;]*[a-zA-Z]//g')

    # Découpe caractère par caractère (en UTF-8)
    i=0
    while IFS= read -r -n1 char; do
        [[ -z "$char" ]] && break
        # Liste partielle des emojis/doubles-largeur (à améliorer si besoin)
        case "$char" in
			[➡️])
                w=1
                ;;
            [✅❌🔥💡🧠🚀📦🔼🔽🔁🔝🔄🔃🎯🛠️🤖👨‍💻👩‍💻📌💾🔐🔍📂])
                w=2
                ;;
            *)
                w=1
                ;;
        esac
        length=$((length + w))
        i=$((i + 1))
    done <<< "$esc_cleaned"

    echo "$length"
}

# Fonction d'affichage du titre centré
print_centered_title() {
    local text="$1"
    local filler="${2:-=}"
    local cols width visible_length pad_left pad_right left_fill right_fill

    # Largeur du terminal (min 20)
    cols=$(tput cols 2>/dev/null || echo 80)
    width=$(( cols < 72 ?  cols : cols / 2 ))

    visible_length=$(get_visible_length "$text")

    # Tronque si trop long
    while [ "$visible_length" -gt "$width" ]; do
        text="${text:1}"
        visible_length=$(get_visible_length "$text")
    done

    pad_left=$(( (width - visible_length) / 2 ))
    pad_right=$(( width - visible_length - pad_left ))

    left_fill=$(head -c "$pad_left" < /dev/zero | tr '\0' "$filler")
    right_fill=$(head -c "$pad_right" < /dev/zero | tr '\0' "$filler")

	echo "${left_fill}${text}${right_fill}"
    echo "${left_fill}${text}${right_fill}" >> $LOG
}

# Fonction d'affichage
# ─── Centre le texte et tronque la partie entre guillemets uniquement si besoin ───
print_centered() {
    local raw_text="$1"
    local filler="${2:- }"
    local cols width visible_length padding pad_right display_text

    # Largeur cible (mini 20, sinon moitié du terminal)
    cols=$(tput cols 2>/dev/null || echo 80)
    width=$(( cols < 72 ? cols : cols / 2 ))

    # Par défaut on affiche le texte complet
    display_text="$raw_text"
    visible_length=$(get_visible_length "$display_text")

    # ── Tronquature ciblée si le texte dépasse ──────────────────────────────────
    if [ "$visible_length" -gt $((width - 2)) ] && [[ "$raw_text" == *\"*\"* ]]; then
        # Sépare préfixe, partie citée et suffixe
        local prefix=${raw_text%%\"*}         # avant le premier "
        local rest=${raw_text#*\"}            # après le premier "
        local quoted=${rest%%\"*}             # entre guillemets
        local suffix=${rest#*\"}              # après le second "

        # On va réduire la partie citée (keep) depuis la gauche
        local keep="$quoted"
        display_text="$prefix\"...$keep\"$suffix"

        # Boucle de réduction jusqu'à rentrer dans la largeur
        while [ "$(get_visible_length "$display_text")" -gt $((width - 2)) ] && [ -n "$keep" ]; do
            keep="${keep:1}"
            display_text="$prefix\"...$keep\"$suffix"
        done
    fi

    # ── Pad à droite pour remplir la ligne ───────────────────────────────────────
    visible_length=$(get_visible_length "$display_text")
    padding=$(( width - visible_length - 2 ))   # -2 pour les barres « | »
    [ "$padding" -lt 0 ] && padding=0
    pad_right=$(head -c "$padding" < /dev/zero | tr '\0' "$filler")

    # ── Affichage final (avec REPLACE éventuel) ─────────────────────────────────
    if [ "${REPLACE:-0}" = "0" ]; then
		printf '\033[%sA\033[2K|%s%s|\n' "$loop" "$display_text" "$pad_right"
		loop=0
    elif [ "${REPLACE:-0}" = "1" ]; then
		loop=$((loop + 1))
		echo $loop
        printf '\033[1A\033[2K|%s%s|\n' "$display_text" "$pad_right"
    else
		sleep 3
		printf '\033[%sA\033[2K|%s%s|\n' "$loop" "$display_text" "$pad_right"
	fi
	printf '|%s%s|\n' "$display_text" "$pad_right" >> $LOG

}

############## SCRIPT ##############
# Remplacement de la commande GIT clone
gclone() {
	loop=0
	REPLACE=1
	DIR_SUB="$CURRENT_DIR"
	if [ ! -d "$DIR_SUB/.git" ]; then
		while [ "$DIR_SUB" != "/" ] && [ "$DIR_SUB" != "." ]; do
        	DIR_SUB=$(dirname "$DIR_SUB")
        	if [ -d "$DIR_SUB/.git" ] || [ -f "$DIR_SUB/.git" ]; then
            	break
        	fi
    	done
	fi
	if [ "$DIR_SUB" ] && [ "$DIR_SUB" != "/" ] && [ "$DIR_SUB" != "." ]; then
		ROOT_DIR=$(git rev-parse --show-toplevel)
		REPO_DIR="${PWD#$ROOT_DIR/}/$REPO_NAME"
		
		print_centered "${YELLOW}🔽 Downloading submodule ${GRAS}\"$REPO_NAME\"${RESET}" " "
		if [ -f "$CURRENT_DIR/.git" ]; then
			cd $CURRENT_DIR
			/bin/git submodule add $2 $REPO_DIR
			/bin/git add -A > /dev/null 2>&1
			/bin/git commit -m "Update of $(date) - Add $REPO_NAME at $REPO_DIR by $(whoami)" > /dev/null 2>&1
			/bin/git push > /dev/null 2>&1
			cd $REPO_NAME
		elif [ -d "$CURRENT_DIR/.git" ]; then
			cd $CURRENT_DIR
			/bin/git submodule add $2 $REPO_DIR
			/bin/git submodule init > /dev/null 2>&1
			/bin/git submodule update > /dev/null 2>&1
		fi
		gbranch $@
		cd $DIR_SUB
		/bin/git add -A > /dev/null 2>&1
		/bin/git commit -m "Update of $(date) - Add $REPO_NAME at $REPO_DIR by $(whoami)" > /dev/null 2>&1
		/bin/git push > /dev/null 2>&1
		REPLACE=0
		print_centered "${GREEN}Submodule ${GRAS}\"$REPO_NAME\"${RESET}${GREEN} downloaded ✅${RESET}"	
	elif [ "$(echo $URL | grep "git@github.com:")" ] && [ "$1" ] && [ "$2" != "--recurse-submodules" ]; then
		print_centered "${YELLOW}🔽 Downloading ${GRAS}\"$REPO_NAME\"${RESET}" " "
		REPLACE=1
		/bin/git $1 $2 $REPO_NAME > /dev/null 2>&1
		LOG=../$LOG
		CURRENT_DIR="$INITIAL_DIR/$REPO_NAME"
		cd $CURRENT_DIR
		if [ -f ".gitmodules" ]; then
			print_centered "${YELLOW}🔽 Downloading submodules${RESET}" " "
			/bin/git submodule update --init --recursive > /dev/null 2>&1
			print_centered "${GREEN}${GRAS}Submodules downloaded ✅${RESET}" " "
			gbranch $@
		fi
		REPLACE=0
		print_centered "${GREEN}${GRAS}\"$REPO_NAME\"${RESET}${GREEN} downloaded ✅${RESET}" " "
		REPLACE=1
	else
		REPLACE=1
		print_centered "${YELLOW}🔽 Downloading ${GRAS}\"$3\"${RESET}" " "
		/bin/git $1 $2 $REPO_NAME > /dev/null 2>&1
		REPLACE=0
		print_centered "${GREEN}Folder ${GRAS}\"$3\"${RESET}${GREEN} downloaded ✅${RESET}" " "
		REPLACE=1
	fi
}

# Remplacement de la commande GIT push
gpush() {
	loop=0
	REPLACE=1
	cd $CURRENT_DIR
	print_centered "🔄 ${YELLOW}Pushing folder ${GRAS}\"$CURRENT_DIR_NAME\"${RESET}" " "
	if [ -f "$CURRENT_DIR/.gitmodules" ]; then
		
		# Sauvegarde de l'emplacement utilisateur
		LAST_PWD=$(pwd)
		CURRENT_DIR=$(echo "$CURRENT_DIR" | sed -E 's|(.*?/42_Paris)(/.*)?|\1|')
		CURRENT_DIR_NAME=$(echo "$CURRENT_DIR" | rev | cut -d'/' -f1 | rev)
		cd $CURRENT_DIR
		# Push des submodules
		for path in $(grep 'path = ' .gitmodules | cut -d'=' -f2 | sed 's/^[[:space:]]*//'); do
    		if [ -d "$path" ]; then
       			print_centered "    🔁 ${YELLOW}Pushing submodule ${GRAS}\"$path\"${RESET}" " "
        		(
            		cd "$path"
					CURRENT_LOG="$CURRENT_LOG/.git/log_42git.log"
					if [ -f "$CURRENT_LOG" ]; then
						echo ici
						cat $LOG >> $CURRENT_LOG
						rm $LOG
					else
						echo la
						mv $LOG $CURRENT_LOG
					fi
            		/bin/git add -A > /dev/null 2>&1
            		/bin/git commit -m "$(pwd) - update of $(date) by $(whoami)" > /dev/null 2>&1
            		/bin/git push origin main_sub > /dev/null 2>&1
        		)
        		print_centered "    ${GREEN}Folder ${GRAS}\"$path\"${RESET}${GREEN} pushed ✅${RESET}" " "
    		else
        		print_centered "    ❌ ${RED}Submodule ${GRAS}\"$path\"${RESET}${RED} unknown${RESET}" " "
				REPLACE=0
    		fi
		done

		# Push du repo principal
		cd $CURRENT_DIR
		/bin/git add -A > /dev/null 2>&1
		/bin/git commit -m "$(pwd) - update of $(date) by $(whoami)" > /dev/null 2>&1
		/bin/git push > /dev/null 2>&1
		REPLACE=0
		print_centered "${GREEN}Main folder ${GRAS}$CURRENT_DIR_NAME ${RESET}${GREEN}pushed ✅${RESET}" " "
		REPLACE=1
	else
		/bin/git add -A > /dev/null 2>&1
		/bin/git commit -m "$(pwd) - update of $(date) by $(whoami)" > /dev/null 2>&1
		/bin/git push > /dev/null 2>&1
		REPLACE=0
		print_centered "${GREEN}${GRAS}$CURRENT_DIR_NAME ${RESET}${GREEN}pushed ✅${RESET}" " "
		REPLACE=1
	fi
}

# Remplacement de la commande GIT pull
gpull() {
	cd $CURRENT_DIR
	loop=0
	REPLACE=1
	if [ -f ".gitmodules" ]; then
		print_centered "${YELLOW}🔼 Pulling ${GRAS}main folder${RESET}" " "
		/bin/git pull > /dev/null 2>&1
		for path in $(grep 'path = ' .gitmodules | cut -d'=' -f2 | sed 's/^[[:space:]]*//'); do
			if [ -d "$path" ]; then
    			print_centered "    🔁 ${YELLOW}Pulling submodule ${GRAS}\"$path\"${RESET}" " "
				cd $CURRENT_DIR/$path > /dev/null 2>&1
           		/bin/git pull origin sub_main > /dev/null 2>&1
        		print_centered "    ${GREEN}${GRAS}Branch of \"$path\" pulled${RESET} ✅" " "
				cd $CURRENT_DIR
    		else
				if [ "$1" = "pull" ]; then
					REPLACE=0
        			print_centered "    ❌ ${RED}${GRAS}Submodule \"$path\" unknown${RESET}" " "
					REPLACE=1
    			fi
			fi
		done
		if [ "$1" = "pull" ]; then
			REPLACE=0
			print_centered "${GREEN}${GRAS}Main folder pulled${RESET} ✅" " "
			REPLACE=1
		fi
	else
		print_centered "${YELLOW}🔼 Pulling ${GRAS}$2${RESET}" " "
		/bin/git "$1" > /dev/null 2>&1
		if [ "$1" = "pull" ]; then
			REPLACE=0
			print_centered "${GREEN}${GRAS}$2 pulled${RESET} ✅" " "
			REPLACE=1
		fi
	fi
}

gbranch() {
	if [ "$1" = "branch" ]; then
		loop=0
	fi
	REPLACE=0
	if [ -f ".gitmodules" ]; then
		REPLACE=1
		print_centered "🔝 ${CYAN}${SOULIGNE}Modify submodule's branch${RESET}" " "
		for path in $(grep 'path = ' .gitmodules | cut -d'=' -f2 | sed 's/^[[:space:]]*//'); do
    		if [ -d "$path" ]; then
       			print_centered "    🔁 ${YELLOW}Switching branch of ${GRAS}\"$path\"${RESET}" " "
        		REPLACE=1
				cd $path > /dev/null 2>&1
            	git fetch > /dev/null 2>&1
				git checkout main_sub > /dev/null 2>&1
				git pull main_sub > /dev/null 2>&1
				cd - > /dev/null 2>&1
				git add $path > /dev/null 2>&1
				git commit -m "$(pwd) - update of $(date) by $(whoami)" > /dev/null 2>&1
				git push > /dev/null 2>&1
         		print_centered "    ${GREEN}${GRAS}Branch of \"$path\" switched${RESET} ✅" " "
    		else
        		print_centered "    ❌ ${RED}${GRAS}Submodule \"$path\" unknown" " "
    		fi
		done
		if [ "$1" = "branch" ]; then
			REPLACE=0
			print_centered "🔝 ${GREEN}${SOULIGNE}Submodule's branch modified${RESET}" " "
			REPLACE=1
		fi
	elif [ -f ".git" ]; then
		print_centered "🔁 ${YELLOW}Switching branch of ${GRAS}\"$CURRENT_DIR_NAME\"${RESET}" " "
		git fetch > /dev/null 2>&1
		git checkout sub_main > /dev/null 2>&1
		git pull origin sub_main > /dev/null 2>&1
		REPLACE=0
		print_centered "    ${GREEN}${GRAS}Branch of \"$CURRENT_DIR_NAME\" switched${RESET} ✅" " "
		REPLACE=1
	else
		git "$@"
	fi
}

# Fonction d'affichage du début
gbegin() {
	if [ "$REPO_NAME" ] && [ ! "$CURRENT_DIR_NAME" ]; then
		print_centered_title "${CYAN}${GRAS}$REPO_NAME${RESET}" "="
		print_centered " " " "
		print_centered "📁 ${BLUE}Folder ➡️  ${BLUE}${GRAS}${SOULIGNE}$REPO_NAME${RESET}" " "
		print_centered " " " "
	else
		if [ "$CURRENT_DIR_NAME" != "." ]; then
			print_centered_title "${CYAN}${GRAS}$CURRENT_DIR_NAME${RESET}" "="
			print_centered " " " "
			print_centered "📁 ${BLUE}Folder ➡️  ${BLUE}${GRAS}${SOULIGNE}$CURRENT_DIR_NAME${RESET}" " "
			print_centered " " " "
		fi
	fi
}

gend() {
	print_centered " " " "
	print_centered_title "=" "="
}

# Enregistrement des logs
log_start() {
	LOG_DIR=$CURRENT_DIR
	if [ ! -d "$LOG_DIR/.git" ]; then
		while [ "$LOG_DIR" != "/" ] && [ "$LOG_DIR" != "." ]; do
        	LOG_DIR=$(dirname "$LOG_DIR")
        	if [ -d "$LOG_DIR/.git" ] || [ -f "$LOG_DIR/.git" ]; then
        	    LOG_DIR_NAME=$(echo "$LOG_DIR" | rev | cut -d'/' -f1 | rev)
        	    break
        	fi
    	done
	fi
	if [ ! -f "$LOG_DIR/.git/$LOG" ] && [ -d "$LOG_DIR/.git" ]; then
		touch "$LOG_DIR/.git/$LOG"
		LOG="$LOG_DIR/.git/$LOG"
	elif [ ! -f "$LOG_DIR/.git/$LOG" ] && [ ! -d "$LOG_DIR/.git/" ]; then
		touch "$LOG"
	else
		LOG="$LOG_DIR/.git/$LOG"
	fi
    print_centered_title "${RED}>> Run command \"git $*\" in the folder ${GRAS}$CURRENT_DIR_NAME ${RESET}${RED}<<${RESET}" "-" > /dev/null 2>&1
    print_centered_title "${YELLOW}$(date)${RESET} by ${YELLOW}$(whoami)${RESET}" " " > /dev/null 2>&1
	print_centered_title " " " " > /dev/null 2>&1
}

log_end() {
    print_centered_title " " " " > /dev/null 2>&1
    print_centered_title "${RED}>> Command \"git $*\" in the folder ${GRAS}$CURRENT_DIR_NAME finished ! ${RESET}${RED}<<${RESET}" "-" > /dev/null 2>&1
	print_centered_title " " " " > /dev/null 2>&1
}

# Remplacement de la commande GIT générale
CURRENT_LOG="$INITIAL_DIR"
CURRENT_LOG_NAME=""

if [ "$3" ]; then
	REPO_NAME=$3
else
    REPO_NAME=$(basename "$2" .git)
fi
if [ -d "$CURRENT_LOG/.git" ]; then
    CURRENT_LOG_NAME=$(echo "$CURRENT_LOG" | rev | cut -d'/' -f1 | rev)
else
	while [ "$CURRENT_LOG" != "/" ] && [ "$CURRENT_LOG" != "." ]; do
        CURRENT_LOG=$(dirname "$CURRENT_LOG")
        if [ -d "$CURRENT_LOG/.git" ]; then
            CURRENT_LOG_NAME=$(echo "$CURRENT_LOG" | rev | cut -d'/' -f1 | rev)
			LOG="$CURRENT_LOG/.git/log_42git.log"
            break
        fi
    done
fi
REPLACE=1
log_start "$@" $CURRENT_DIR_NAME
gbegin
if [ "$1" = "clone" ]; then
	gclone $@ $CURRENT_DIR_NAME
elif [ "$1" = "push" ]; then
	gpull $@ $CURRENT_DIR_NAME > /dev/null 2>&1
	gpush $@ $CURRENT_DIR_NAME
elif [ "$1" = "pull" ]; then
	gpull $@ $CURRENT_DIR_NAME
elif [ "$1" = "branch" ]; then
	gbranch $@ $CURRENT_DIR_NAME
else
	/bin/git "$@"
fi
gend
log_end "$@" $CURRENT_DIR_NAME