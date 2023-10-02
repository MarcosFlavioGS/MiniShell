/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:21:35 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/29 10:01:51 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# define ERR_HDOC_02 "heredoc[ERR_HDOC_2]: write the entered line in temp file"
# define ERR_HDOC_03 "heredoc[ERR_HDOC_3]: write new line in the file"
# define ERR_HDOC_04 "heredoc[ERR_HDOC_4]: create the temporary file"
# define ERR_HDOC_06 "heredoc[ERR_HDOC_6]: open temporary file on (read mode)"
# define ERR_HDOC_07 "heredoc[ERR_HDOC_7]: close the temp file fd (write mode)"

# define TEMP_FILE "/tmp/3452-042--24023-044sf-mfs.txt"

int	make_heredoc(char *limiter);

#endif