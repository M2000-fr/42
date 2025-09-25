/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:25:31 by mechard           #+#    #+#             */
/*   Updated: 2025/07/16 14:25:31 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TEXT_HPP
# define TEXT_HPP

/* TEXT STYLE */
# define STANDARD       "\033[0m"
# define BOLD           "\033[1m"
# define UNDERLINE      "\033[4m"
# define INVERT         "\033[7m"
# define MASKED         "\033[8m"

/* TEXT COLOR */
# define BLACK          "\033[30m"
# define RED            "\033[31m"
# define GREEN          "\033[32m"
# define YELLOW         "\033[33m"
# define BLUE           "\033[34m"
# define MAGENTA        "\033[35m"
# define CYAN           "\033[36m"
# define WHITE          "\033[37m"

/* TEXT RESET */
# define RESET          STANDARD

#endif