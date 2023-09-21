/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:46:55 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/21 16:43:28 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


bool is_operator(const std::string& token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

double perform_operation(double a, double b, const std::string& op)
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Invalid operator: " + op);
}

double evaluate_rpn(const std::string& expression)
{
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (!is_operator(token))
        {
            double number;
            if (!(std::istringstream(token) >> number))
                throw std::runtime_error("Invalid token: " + token);
            stack.push(number);
        }
        else
        {
            if (stack.size() < 2)
                throw std::runtime_error("Insufficient operands for operator: " + token);
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            double result = perform_operation(a, b, token);
            stack.push(result);
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Invalid expression");
    
    return stack.top();
}