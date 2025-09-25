#!/bin/zsh
tput civis
stty -echo
trap "tput cnorm; exit" INT TERM EXIT

# Menu de sélection d'utilisateur interactif (Zsh / WSL)
setopt KSH_ARRAYS
USERS=($(awk -F: '$3 >= 1000 && $3 != 65534 && $7 ~ /(bash|zsh|sh)/ { print $1 }' /etc/passwd))
current=0
total_users=${#USERS[@]}

# Calcul largeur dynamique
max_name_length=0
for u in "${USERS[@]}"; do
	[ ${#u} -gt $max_name_length ] && max_name_length=${#u}
done
box_width=$((max_name_length + 30))
box_inner=$((box_width - 2))

# Centrage du titre
title="Sélection de l'utilisateur"
title_length=${#title}
padding_left=$(( (box_inner - title_length) / 2 ))
padding_right=$(( box_inner - title_length - padding_left ))
title_line="│$(printf '%*s' $padding_left '')$title$(printf '%*s' $padding_right '')│"

draw_menu() {
	echo
	echo "┌$(printf '─%.0s' $(seq 1 $box_inner))┐"
	echo "$title_line"
	echo "├$(printf '─%.0s' $(seq 1 $box_inner))┤"

	for i in $(seq 0 $((total_users - 1))); do
		if [ "$i" -eq "$current" ]; then
			printf "│ > \033[30;47m%-*s\033[0m│\n" $((box_inner - 3)) "${USERS[i]}"
		else
			printf "│  \033[32m%-*s\033[0m │\n" $((box_inner - 3)) "${USERS[i]}"
		fi
	done

	echo "└$(printf '─%.0s' $(seq 1 $box_inner))┘"
}

clear_menu() {
	total_lines=$((total_users + 5))  # utilisateurs + cadre + vide
	for _ in $(seq 0 $total_lines); do
		tput cuu1
		tput el
	done
}

# Fonction principale de sélection
select_user() {
	current=0
	while true; do
		draw_menu
		IFS= read -k1 input
		if [[ "$input" == $'\e' ]]; then
			read -k2 -t 0.001 rest  # lire les deux touches suivantes (ex: [A ou [B)
			input+="$rest"
		fi

		case "$input" in
			$'\t'|$'\e[B')  # Tab ou Flèche bas
				current=$(( (current + 1) % total_users ))
				;;
			$'\e[A')  # Flèche haut
				current=$(( (current - 1 + total_users) % total_users ))
				;;
			$'\n'|$'\r')  # Entrée
				break
				;;
			q)
				echo "Sortie manuelle.\n"
				stty echo
				tput cnorm
				exit 0
				;;
		esac
		clear_menu
	done

	selected_user="${USERS[$current]}"

	if [ "$selected_user" = "$USER" ]; then
  		clear
  		echo "Oh shit ! Here we go again $USER..."
		stty echo
		tput cnorm
  		return
	elif id "$selected_user" >/dev/null 2>&1 || [ "$selected_user" = "$USER" ]; then
  		clear
  		if [ "$selected_user" = "mechard" ]; then
			printf "%b\n" \
			"\033[1;37m                   |\033[0m" \
			"\033[1;37m                  / \\\ \033[0m" \
			"\033[1;36m                 |―O―|\033[0m" \
			"\033[1;36m                 |   |\033[0m" \
			"\033[1;36m                /|   |\\\ \033[0m" \
			"\033[1;36m               /_|___|_\\\ \033[0m" \
			"\033[0;33m                /_\\ /_\\\ \033[0m" \
			"\033[0;33m                \\_/ \\_/\033[0m" \
			"\033[0;31m                 /   \\\ \033[0m" \
			"\033[0;31m                /     \\\ \033[0m" \
			"\033[0;31m               /       \\\ \033[0m" \
			"\033[0;31m              /_________\\\ \033[0m" \
			"🚀🚀🚀 \033[1;34mDirection les étoiles Maxime !\033[0m 🚀🚀🚀"
  		else
    		echo "✅ Vous êtes connecté en tant que '$selected_user'."
  		fi
		stty echo
		tput cnorm
  		exec sudo -u "$selected_user" -i
	else
		echo "⚠️  Utilisateur inexistant : '$selected_user'"
  		sleep 1
  		clear
  		select_user
	fi
	}

select_user                                           
                                                                                                    