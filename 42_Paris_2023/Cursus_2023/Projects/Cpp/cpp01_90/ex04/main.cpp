/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:29:54 by mechard           #+#    #+#             */
/*   Updated: 2025/03/15 19:29:54 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <fichier> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    if (s1.empty())
    {
        std::cerr << "La chaîne s1 ne doit pas être vide." << std::endl;
        return 1;
    }

    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Erreur lors de l'ouverture du fichier : " << filename << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(infile, line))
    {
        content += line;
        if (!infile.eof())
            content += "\n";
    }
    infile.close();

    std::string result;
    std::size_t pos = 0;
    std::size_t found;
    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(content, pos, content.length() - pos);

    std::string outFilename = filename + ".replace";
    std::ofstream outfile(outFilename.c_str());
    if (!outfile)
    {
        std::cerr << "Erreur lors de l'ouverture du fichier de sortie : " << outFilename << std::endl;
        return 1;
    }

    outfile << result;
    outfile.close();

    return 0;
}
