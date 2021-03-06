/*
 Copyright (C) 2015-2016 Alexander Borisov
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 
 Author: lex.borisov@gmail.com (Alexander Borisov)
*/

#ifndef MyHTML_def_H
#define MyHTML_def_H
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define myhtml_parser_skip_whitespace()                                                      \
if(myhtml_whithspace(html[html_offset], ==, ||)) {                                           \
    while (html_offset < html_size && (myhtml_whithspace(html[html_offset], ==, ||))) {      \
        html_offset++;                                                                       \
    }                                                                                        \
}

#define myhtml_parser_queue_set_attr(tree, qnode)                                       \
    if(qnode->token->attr_first == NULL) {                                              \
        qnode->token->attr_first = myhtml_tree_token_attr_current(tree);                \
        qnode->token->attr_last  = qnode->token->attr_first;                            \
                                                                                        \
        tree->attr_current = qnode->token->attr_last;                                   \
        tree->attr_current->next = NULL;                                                \
        tree->attr_current->prev = NULL;                                                \
    }                                                                                   \
    else {                                                                              \
        qnode->token->attr_last->next = myhtml_tree_token_attr_current(tree);            \
        qnode->token->attr_last->next->prev = qnode->token->attr_last;                   \
        qnode->token->attr_last = qnode->token->attr_last->next;                         \
                                                                                        \
        qnode->token->attr_last->next = NULL;                                           \
        tree->attr_current = qnode->token->attr_last;                                   \
    }

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
