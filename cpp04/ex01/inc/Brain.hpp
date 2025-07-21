/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:01:40 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 16:01:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
    private:
    static const int _maxIdeas = 100;
    
    protected:
        std::string _ideas[_maxIdeas];
    
    public:
        /* ***** Constructors and Destructor **** */
        Brain(void);
        Brain(const Brain &other);
        ~Brain(void);

        /* ******** Assignment operator ********* */
        Brain& operator=(const Brain &other);

        /* ********** Method Functins *********** */
        std::string getIdea(int index);
        void        setIdea(int index, std::string idea);
};

#endif