clc; clear; close all;

folder = '/Users/baohongyin/Desktop/Advanced_CFD/C++_Code/CFD_Basic/Stage2_Advective_Wave_Equation_SimplePCWE/output/Instant';
files = dir(fullfile(folder, 'psi_analytical_step_*.csv'));

file_names = {files.name};
step_nums = zeros(size(file_names));
for k = 1:length(file_names)
    step_nums(k) = sscanf(file_names{k}, 'psi_analytical_step_%d.csv'); 
end
[~, idx] = sort(step_nums);
files_sorted = file_names(idx);


video_filename = fullfile(folder, 'wave_animation.mp4');
v = VideoWriter(video_filename, 'MPEG-4');
v.FrameRate = 20;  
open(v);


figure('Color','w');
hLine = plot(nan, nan, 'b','LineWidth',2); 
xlabel('x'); ylabel('\psi(x,t)');
title('Advective Wave Equation');
grid on;
hold on;

ylim([0, 1]);

xlim([-1, 1]);

for k = 1:length(files_sorted)
    filename_num = fullfile(folder, files_sorted{k});
    
    data = readmatrix(filename_num);
    x = data(:,1);
    psi_num = data(:,2);
    

    set(hLine, 'XData', x, 'YData', psi_num);
    
    step_num = sscanf(files_sorted{k}, 'psi_step_%d.csv');
    t = step_num * 0.005; 
    title(sprintf('Advective Wave Equation, t = %.3f', t));
    
    drawnow;
    
    frame = getframe(gcf);
    writeVideo(v, frame);
end

% -------------------------
% 6. 关闭视频文件
% -------------------------
close(v);
disp(['MP4 video saved to: ', video_filename]);
